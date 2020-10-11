FROM fedora:32

WORKDIR /src/libnmpatch

RUN dnf install -y \
        autoconf \
        automake \
        libtool \
        g++ \
        make \
        diffutils \
        flex \
        bison \
        tcl-devel \
    ; \
    dnf clean all;

COPY --from=4c0n/libpdl:latest /usr/local/include /usr/include
COPY --from=4c0n/libpdl:latest /usr/local/lib/libpdl.la /usr/lib/libpdl.la
COPY --from=4c0n/libpdl:latest /usr/local/lib/libpdl.a /usr/lib/libpdl.a

COPY --from=4c0n/libppf:latest /usr/local/include /usr/include
COPY --from=4c0n/libppf:latest /usr/local/lib/libppf.la /usr/lib/libppf.la
COPY --from=4c0n/libppf:latest /usr/local/lib/libppf.a /usr/lib/libppf.a

COPY . /src/libnmpatch

RUN set -eux; \
    aclocal; \
    libtoolize; \
    automake --add-missing && ls -lah; \
    autoreconf; \
    ./configure; \
    make; \
#    make check; \
    make install;

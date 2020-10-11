/*
    Nord Modular patch file format 3.03 parser
    Copyright (C) 2002 Marcus Andersson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>

using namespace std;

#if ! defined(YYSTYPE)
#define YYSTYPE string
#endif

#if ! defined(yyFlexLexer)
#define yyFlexLexer nmFlexLexer
#include <FlexLexer.h>
#endif

#if ! defined(yywrap)
#define yywrap nmwrap
#endif

extern "C" {
  int nmwrap(void);
}

class NMLexer : public nmFlexLexer {
public:
	NMLexer( std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0 );
protected:
};

#endif

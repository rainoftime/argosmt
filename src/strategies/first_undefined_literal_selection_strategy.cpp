/****************************************************************************
argosmt (an open source SMT solver)
Copyright (C) 2010-2014 Milan Bankovic (milan@matf.bg.ac.rs)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public Lcense
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
***************************************************************************/

#include "first_undefined_literal_selection_strategy.hpp"
#include "solver.hpp"

bool first_undefined_literal_selection_strategy::
select_decision_literal(expression & decision_literal)
{
  const expression_vector & literals = _solver.literals();
  
  for(unsigned i = 0; i < literals.size(); i += 2)
    if(_solver.get_trail().is_undefined(literals[i]))
      {
	decision_literal = literals[i];
	return true;
      }
  
  return false;
}

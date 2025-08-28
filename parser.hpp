#pragma once
#include <iostream>
#include <memory>
#include "ast.hpp"

// Forward declaration of the parser function
std::unique_ptr<Spec> parse_spec(std::istream& in);

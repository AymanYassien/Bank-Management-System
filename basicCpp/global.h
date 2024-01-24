//
// Created by Ayman yassien on 06/01/2024 AD.
//
#pragma once
#include "clsUser.h"
#include "clsDate.h"

clsUser currentUser = clsUser::find("", "");
string currentDate = clsDate::convertDateStructToString(clsDate::getSystemDate());
//short trails = 3;
// dummy find = this = find by placeholder
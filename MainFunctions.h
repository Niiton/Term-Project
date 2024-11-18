#pragma once 
#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "CheckingAccount.h"
#include "SavingAccount.h"

void printMainMenu();

void printViewOptions();

void printModifyOptionsChecking();
void printModifyOptionsSaving();

void deposit(CheckingAccount& acc);

void deposit(SavingAccount& acc);

void withdraw(CheckingAccount& acc);

void withdraw(SavingAccount& acc);

void getAndModAllInputChecking(CheckingAccount& Checking);

void getAndModAllInputSaving(SavingAccount& Saving);

//Rearranges checking accounts if an account is deleted, explicit use in deleteAccount();
void rearrangeCheckingAccs(CheckingAccount checking[], int checkingCount);

void deleteAccount(CheckingAccount checkingArr[], int& checkingCount, int accToModify);

//Rearranges saving accounts if an account is deleted, explicit use in deleteAccount();
void rearrangeCheckingAccs(SavingAccount saving[], int savingCount);

void deleteAccount(SavingAccount savingArr[], int& savingCount, int accToModify);
#endif !MAIN_FUNCTIONS_H
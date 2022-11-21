pragma solidity >0.4.11;
// SPDX-License-Identifier: UNLICENSED
 
contract Bank {
    uint balance;
 
    // event Deposit(uint val);
    // event Withdraw(uint val);
 
    function deposit(uint amt) public returns(uint) {
        balance += amt;
        return 1;
    }
    function withdraw(uint amt) public returns(uint) {
        if(amt > balance) {
            return 0;
        }
        balance -= amt;
        return 1;
    }
    function showBalance() view public returns(uint) {
        return balance;
    } 
}

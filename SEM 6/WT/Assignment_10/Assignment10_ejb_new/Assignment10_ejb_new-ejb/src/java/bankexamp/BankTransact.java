/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/J2EE/EJB30/StatefulEjbClass.java to edit this template
 */
package bankexamp;

import javax.ejb.Stateful;

/**
 *
 * @author ACER
 */
@Stateful
public class BankTransact implements BankTransactLocal {

    //default balance = 1000
    
    int balance = 1000;

    @Override
    public void deposit(int amount) {
        balance  = balance + amount;
    }

    @Override
    public int withdraw(int amount) {
        balance = balance - amount;
        return balance;
    }
     
}

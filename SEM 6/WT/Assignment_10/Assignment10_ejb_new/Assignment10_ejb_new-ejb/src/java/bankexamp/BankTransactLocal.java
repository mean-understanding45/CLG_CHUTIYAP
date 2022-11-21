/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/J2EE/EJB30/SessionLocal.java to edit this template
 */
package bankexamp;

import javax.ejb.Local;

/**
 *
 * @author ACER
 */
@Local
public interface BankTransactLocal {

    void deposit(int amount);

    int withdraw(int amount);
    
}

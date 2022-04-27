package login;

import com.opensymphony.xwork2.ActionSupport;

public class LoginAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	String uname, mobile, email ;
	
	public String getUname() {
		return uname;
	}

	public void setUname(String uname) {
		this.uname = uname;
	}

	public String getMobile() {
		return mobile;
	}

	public void setMobile(String mobile) {
		this.mobile = mobile;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String execute() {
		
		// validation

		if (uname.length()>15) {
			return "usernameError" ;
		}else {
			
			if (mobile.length()!=10) return "mobileError";
			else {
				
				if (email.indexOf("@")==-1) return "emailError";
				else
					return "success";
				
			}
			
		}
	
	}


}

pragma solidity >0.4.11;
// SPDX-License-Identifier: UNLICENSED
 
contract StudentInfo {
    struct Student {
        string id;
        string name;
        string contactNo;
    }
    Student[20] studInfoArray;
    uint i=0;
    function registerStudent(string memory _stud_id, string memory _name, string memory _contact) public returns(string memory) {
        Student memory student = Student(_stud_id, _name, _contact);
 
        if(i > 20) {
            return "Memory limit exhausted";
        }
        else {
            studInfoArray[i] = student;
            i += 1;
            return "Student registered successfully!";
        }        
    }
 
    function getStudent(uint idx) public view returns(string memory){
        Student memory student = studInfoArray[idx];
        return string(abi.encodePacked("Name: ", bytes(student.name), ", Contact No.: ", 
        bytes(student.contactNo), ", Seat No: ", bytes(student.id)));
        // return string(bytes.concat("Name: ", bytes(student.name), ", Contact No.: ", 
        // bytes(student.contactNo), ", Seat No: ", bytes(student.id)));

    }
    // The solidity fallback function is executed if none of the other functions match the function identifier
    // or no data was provided with the function call. Only one unnamed function can be assigned to a contract
 
   fallback(bytes calldata) external payable returns (bytes memory) {
        return "fallback called!";
    }

    receive() external payable{
    }
}

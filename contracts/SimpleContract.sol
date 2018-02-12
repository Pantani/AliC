pragma solidity ^0.4.18;

contract Owner {
    address public owner;
    modifier onlyOwner() {
        require (msg.sender == owner);
        _;
    }
  function destroir() onlyOwner public {
    selfdestruct(owner);
  }    

  function kill() public onlyOwner {
      selfdestruct(0);
  }  
}

contract SimpleContract is Owner {

    string public email;
    string public name;
    string public doc;
    bool public paid = false;

    event LogChangeName(string _name, address _contract);
    event LogChangeDocument(string _document, address _contract);
    event LogPay(bool paid, address _contract);
    
    function SimpleContract (string _name, string _doc, string _email) public {
        owner = msg.sender;
        name = _name;
        doc = _doc;
        email = _email;
    }

    function changeName (string _newName) public onlyOwner {
        name = _newName;
        LogChangeName(name, this);
    }

    function changeDocument (string _newDocument) public onlyOwner {
        doc = _newDocument;
        LogChangeDocument(doc, this);
    }

    function setPaid (bool _paid) public {
        paid = _paid;
        LogPay(paid, this);
    }
}
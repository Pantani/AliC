pragma solidity ^0.4.18;

contract SimpleContract {
    uint public number;
    address public owner;

    function SimpleContract () public {
        owner = msg.sender;
        number = 12333;
    }

    function changeNumber(uint _newNumber) public {
        require (msg.sender == owner);
        number = _newNumber;
    }
}
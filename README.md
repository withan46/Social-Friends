# Social-Friends
<img src="https://user-images.githubusercontent.com/72460876/170507549-f5c16095-f1e9-4556-b1ad-79e63f058b5b.png" width="20" height="20">  University project:

* This project was made with C. 
* To solve this problem I used tables and worked with neighbor arrays. 
* For more information about the project I used enough comments inside the code so it could be easier the code to be understood.
* Downbelow is a pseudocode, explaining the functions.

# Pseudocode

**This program calculates the number of people who can come to the party and find who are
these people <br>**

```
function findDearOnes(integer array members, character array of names, boolean array S ,
Argument people){
    Make new array which they will be stored stathis party visitors
    Find If someone from his friends does not hate anyone and invite him in party
    Add the number of people that can come in party in people argument
  return to main people
end
}

function findInvitations(integer array members, character array of names, boolean array S ,
Argument people){
      Make new array which they will be stored stathis party visitors
      Find the best solution for whom to invite to the party (we take all leaves,
      remove them from the graph and make new without them ,and
      without parent’s leaves by changing S array (false when we remove node)
      Add the removed nodes in invite array
      Add the number of people that can come in party in people argument
      
    return to main people
  end
}

function makeNeighborArray(integer array members){
    Make neighborArray array
    Fill array with 1 if someone hate someone else 0 if he is ok with him
    Array is Diagonal
    
    return to main array
  end
}

In the main function {
    names array has the names of Stathis friends
    members array has the hate relations between Stathis friends
    S array save when someone is in party list
    Find hate relations using makeNeighborArray
    Find guests using findDearOnes - findInvitations
    print results
}
```

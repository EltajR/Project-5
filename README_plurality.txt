
# CS50 - Project - Voting system (plurality-based)
Create a voting system that finds out the winner(s) of the election based on the user input
through console
Detailed problem description: https://cs50.harvard.edu/x/2022/psets/3/plurality/


 - Candidate names have to be entered with a space in-between them!
 - Note that the program is case-sensitive (capital - lowercase matter)
 - Implemented from scratch according to the problem description
 - Maximum number of voters as well as votes set to 9
 - Deals with invalid votes as well as invalid number of votes
 - Fulfills all the requirements set out in the problem description


 What could be improved in next versions:

 - It cannot deal with the case when the user enters string instead of
   a number in 'Number of voters' field
 - At the end of the program, we have to loop through candidates array twice:
   once to find the max_votes and once more to find the candidates who have the max_vote_count -
   this could perhaps be avoided by merging these operations into one function(loop)
 - It cannot handle if the user enters more than 9 candidate names (probably segmentation fault will happen)


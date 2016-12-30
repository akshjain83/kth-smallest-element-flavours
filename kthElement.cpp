#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int findKthElement(vector<int> &inputSet, int k)
{
   //Validation for 'k'; K can only be between 1 and Number of Elements
   if(k > inputSet.size() || k <= 0){
      cout<<"Impossible here\nThis is not valid k value:  ";
      return k;
   }

   //Queue to hold upto smallest k elements
   priority_queue<int> queuedElements;

   //Counter to keep track of number of elements in Priority Queue
   //Increment everytime we insert new element in PQ
   int countOfElementsInQ = 0;

   //Iteration over the given inputSet to find kth smallest
   for(int i = 0; i < inputSet.size(); i++)
   {
      //If first element from input i.e Priority Queue doesnot hold anything
      if(queuedElements.empty())
      {
         queuedElements.push(inputSet[i]);
         countOfElementsInQ++;
      }

      //If Elements from input already in Priority Queue
      else 
      {
         /*Check whether PQ have exactly k elements; If it does then
          remove larger element and insert smaller i.e. current element in 
          iteration is smaller then root element then execute following*/
         if(countOfElementsInQ == k)
         {
            
            //Since popping one element and at the same time pushing one 
            //element we dont increment or decrement counterOfElementsInQ
            if(queuedElements.top() > inputSet[i]){
               queuedElements.pop();
               queuedElements.push(inputSet[i]);
            }
         }

         //Hold Upto K Elements in Priority Queue
         else if(countOfElementsInQ < k)
         {
            queuedElements.push(inputSet[i]);
            countOfElementsInQ++;
         } 
      }
   }

   /* Since the priority queue holds k number of elements starting from
   kth smallest, kth - 1 smallest...and so on; we just return kth smallest
   as the top of PQ since we have stored it that way in this algorithm*/
   return queuedElements.top();
}


int main()
{
   //vector<int> inputSet {2,11,-10,20,1}; 
   vector<int> inputSet {3,7,-13,5,2}; 

   cout<<endl<<"The Kth Smallest Number is: ";
   cout<<findKthElement(inputSet,2)<<endl;


}

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int findKthElement(vector<int> &inputSet, int k)
{

   if(k > inputSet.size() || k <= 0){
      cout<<"\nThis is not valid k value:  ";
      return k;
   }

   priority_queue<int> queuedElements;
   int countOfElementsInQ = 0;
   for(int i = 0; i < inputSet.size(); i++)
   {
      if(queuedElements.empty() && countOfElementsInQ < k)
      {
         queuedElements.push(inputSet[i]);
         countOfElementsInQ++;
      }
      else 
      {
         if(!queuedElements.empty() && countOfElementsInQ == (k))
         {
            if(queuedElements.top() > inputSet[i]){
               queuedElements.pop();
               queuedElements.push(inputSet[i]);
            }
         }
         else if(!queuedElements.empty() && countOfElementsInQ < k)
         {
            queuedElements.push(inputSet[i]);
            countOfElementsInQ++;
         } 
      }
   }
   return queuedElements.top();
}


int main()
{
   vector<int> inputSet {2,11,-10,20,1}; 
   cout<<endl<<"The Kth Smallest Number is: "<<findKthElement(inputSet,2)<<endl;


}

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int findKthElement(vector<int> &input, int k)
{

   if(k > input.size() || k <= 0){
      cout<<"\nThis is not valid k value:  ";
      return k;
   }


   priority_queue<int> qElements;
   int countOfElementsInQ = 0;
   for(int i = 0; i < input.size(); i++)
   {
      if(qElements.empty() && countOfElementsInQ < k)
      {
         qElements.push(input[i]);
         countOfElementsInQ++;
      }
      else 
      {
         if(!qElements.empty() && countOfElementsInQ == (k))
         {
            if(qElements.top() > input[i]){
               qElements.pop();
               qElements.push(input[i]);

            }

         }
         else if(!qElements.empty() && countOfElementsInQ < k)
         {
            qElements.push(input[i]);
            countOfElementsInQ++;
         } 
      }

   }
   return qElements.top();
}


int main()
{
   vector<int> input; 
   input.push_back(2);
   input.push_back(11);
   input.push_back(-10);
   input.push_back(20);
   input.push_back(1);
   cout<<endl<<endl<<findKthElement(input,2)<<endl<<endl;


}

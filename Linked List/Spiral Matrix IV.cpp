// You are given two integers m and n, which represent the dimensions of a matrix.

// You are also given the head of a linked list of integers.

// Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

// Return the generated matrix.








class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>>ans(m, vector<int>(n, -1));

        int i=0;
        int j=0;


        int right=n-1;
        int left=0;

        int top=0;
        int bottom = m-1;


        while(head!=NULL){

            while(head!=NULL && j<=right){
                ans[i][j]=head->val;
                head=head->next;
                j++;
            }

            
            j--;

            top++;

            i++;

            while(head!=NULL && i<=bottom){
                ans[i][j]=head->val;
                head=head->next;
                i++;
            }


            i--;

            right--;

            j--;

            while(head!=NULL && j>=left){
                ans[i][j]=head->val;
                head=head->next;
                j--;
            }


            j++;

            bottom--;

            i--;



            while(head!=NULL && i>=top){
                ans[i][j]=head->val;
                head=head->next;
                i--;
            }



            i++;

            j++;

            left++;



            i=top;
            j=left;

        }


        return ans;

        
    }
};

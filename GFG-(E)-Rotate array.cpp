// Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 



     void rotateArr(int arr[], int d, int n){
         // code here
         
        d%=n;
        
         reverse(arr, arr+d);
         reverse(arr+d, arr+n);
          reverse(arr, arr+n);
     }
    
    
    
//     void reverse(int arr[], int start, int end) {
//     while (start < end) {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

// void rotateArr(int arr[], int d, int n) {
//     // Code to rotate the array 'd' times to the left
//     reverse(arr, 0, d - 1);
//     reverse(arr, d, n - 1);
//     reverse(arr, 0, n - 1);
// }

//   static void rotateArr(int arr[], int d, int n)
//     {
//         // add your code here
//         d%=n;//because what happens when d is more than n
//         rotate(arr,0,d-1);
//         rotate(arr,d,n-1);
//         rotate(arr,0,n-1);
//     }
//     static void rotate(int arr[],int low,int high){
//         int temp=0;
//         while(low<high){
//             temp=arr[low];
//             arr[low]=arr[high];
//             arr[high]=temp;
//             low++;
//             high--;
//         }
//     }



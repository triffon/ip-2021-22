#include <iostream>

int main()
{
    int arr[200], freq[200];
    int arrSize, count;

    std::cout << ("Enter size of array: ");
    std::cin >> arrSize;
    //check if arrSize < 200
    
    printf("Enter elements in array: ");
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> arr[i];

        freq[i] = -1;
    }


    for (int i = 0; i < arrSize; i++)
    {
        count = 1;
        for (int j = i + 1; j < arrSize; j++)
        {
            //Check for duplicates
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }

        if (freq[i] != 0)
        {
            freq[i] = count;
        }
    }

   
    std::cout << "Occurencies: \n";
    for (int i = 0; i < arrSize; i++)
    {
        if (freq[i] != 0)
        {
            std::cout << "Number " << arr[i] << " occurs " << freq[i] << " times\n";
        }
    }

    return 0;
}

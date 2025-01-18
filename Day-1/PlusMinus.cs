using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<int> arr)
    {
        int positiveCount = 0;
        int negativeCount = 0;
        int zeroCount = 0;
        
        int Length = arr.Count;
        
        foreach(int num in arr)
        {
            if (num > 0) positiveCount++;
            else if (num < 0) negativeCount++;
            else zeroCount++;
            
        }
        
        double positiveRatio = (double) positiveCount/Length;
        double negativeRatio = (double) negativeCount/Length;
        double zeroRatio = (double) zeroCount/Length;
        
        Console.WriteLine(positiveRatio);
        Console.WriteLine(negativeRatio);
        Console.WriteLine(zeroRatio);

    }

}

class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        Result.plusMinus(arr);
    }
}

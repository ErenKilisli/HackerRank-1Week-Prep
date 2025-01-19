using System.CodeDom.Compiler;
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
     * Complete the 'superDigit' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING n
     *  2. INTEGER k
     */
    
    public static int iterativeSum(string n)
    {
        long digitSum = 0;

        for (int i = 0; i < n.Length; i++)
        {
            digitSum += n[i] - '0'; 
        }

        return (int)digitSum; 
    }

    public static int superDigit(string n, int k)
    {

        long digitSum = (long)iterativeSum(n) * k;


        while (digitSum >= 10)
        {
            long newSum = 0;
            while (digitSum > 0)
            {
                newSum += digitSum % 10; 
                digitSum /= 10; 
            }
            digitSum = newSum; 
        }

        return (int)digitSum; 
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

        string n = firstMultipleInput[0];

        int k = Convert.ToInt32(firstMultipleInput[1]);

        int result = Result.superDigit(n, k);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}

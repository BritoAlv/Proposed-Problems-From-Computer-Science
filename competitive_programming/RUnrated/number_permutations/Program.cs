﻿public class Test
{
    public static void Main()
    {
        long mod = 998244353;
        int n = int.Parse(Console.ReadLine());
        int counter = n;
        int[] first_sequence = new int[n];
        int[] second_sequence = new int[n];
        while (counter > 0)
        {
            string[] pair = Console.ReadLine().Split();
            first_sequence[n - counter] = int.Parse(pair[0]);
            second_sequence[n - counter] = int.Parse(pair[1]);
            counter--;
        }
        long answera = algone(n, first_sequence, mod) % mod;
        long answerb = algone(n, second_sequence, mod) % mod;
        long intersection = algtwo(n, first_sequence, second_sequence, mod) % mod;
        long answer = (answera + answerb) % mod;
        answer = (answer - intersection) % mod;
        if (answer < 0)
        {
            answer = answer + mod;
        }
        answer = ((n_factorial_mod(n, mod) - answer)) % mod;
        if (answer < 0)
        {
            answer = answer + mod;
        }
        Console.WriteLine(answer);
    }

    public static long algone(int n, int[] arry, long mod)
    {
        long answer = 1;
        int[] bucket = new int[n];
        for (int i = 0; i < arry.Length; i++)
        {
            bucket[arry[i] - 1]++;
        }
        foreach (var item in bucket)
        {
            answer = (n_factorial_mod(item, mod) * answer) % mod;
        }
        return answer;
    }

    public static long algtwo(int n, int[] first, int[] second, long mod)
    {
        long answer = 1;
        Dictionary<(int, int), int> multiset = new Dictionary<(int, int), int>();
        for (int i = 0; i < n; i++)
        {
            var item = (first[i], second[i]);
            if (!multiset.ContainsKey(item))
            {
                multiset[item] = 0;
            }
            multiset[item]++;
        }
        Array.Sort(first);
        Array.Sort(second);
        long count = 0;
        int last_visited_first = first[0];
        int last_visited_second = second[0];
        for (int i = 0; i < n; i++)
        {
            if (multiset.ContainsKey((first[i], second[i])))
            {
                multiset[(first[i], second[i])]--;
                if (multiset[(first[i], second[i])] == 0)
                {
                    multiset.Remove((first[i], second[i]));
                }
                if (last_visited_first == first[i] && last_visited_second == second[i])
                {
                    count++;
                    answer = (answer * count) % mod;
                }
                else
                {
                    last_visited_first = first[i];
                    last_visited_second = second[i];
                    count = 1;
                }
            }
            else
            {
                return 0;
            }
        }
        return answer;
    }
    public static long n_factorial_mod(int n, long mod)
    {
        if (n <= 1)
        {
            return 1;
        }
        long answer = 1;
        for (int i = 2; i <= n; i++)
        {
            answer = (answer * i) % mod;
        }
        return answer;
    }
}
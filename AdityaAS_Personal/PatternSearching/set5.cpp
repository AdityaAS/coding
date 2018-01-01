// Set 5: Finite Automata 
// TODO

// #include <string.h>
// #include <math.h>
// #define NO_OF_CHARS 256
// #include <stdio.h>

// using namespace std;

// Finite Automata based Pattern Search Algorithm
// Time Complexity: O(n) worst case
// Space Complexity: O(m*NO_OF_CHARS)

// n - Length of text
// m - Length of pattern being searched
// int prime = 101;

// // Is there a possibility of overflow in this code? During the calculation of the hash value / rehash value
// int getNextState(char *pat, int M, int state, int x)
// {
//     if (state < M && x == pat[state])
//         return state+1;
//     int ns, i;
//     for (ns = state; ns > 0; ns--)
//     {
//         if (pat[ns-1] == x)
//         {
//             for (i = 0; i < ns-1; i++)
//                 if (pat[i] != pat[state-ns+1+i])
//                     break;
//             if (i == ns-1)
//                 return ns;
//         }
//     }
//     return 0;
// }

// void makeAutomata(char *pat, int M, int TF[][NO_OF_CHARS])
// {
//     int state, x;
//     for (state = 0; state <= M; ++state)
//         for (x = 0; x < NO_OF_CHARS; ++x)
//             TF[state][x] = getNextState(pat, M, state, x);
// }

// void searchAutomata(char *pat, char *txt)
// {
//     int M = strlen(pat);
//     int N = strlen(txt);
//     int TF[M+1][NO_OF_CHARS];
//     makeAutomata(pat, M, TF);
//     int i, state=0;
//     for (i = 0; i < N; i++)
//     {
//         state = TF[state][txt[i]];
//         if (state == M)
//             printf ("\n Pattern found at index %d",
//                                            i-M+1);
//     }
// }

// int main(int argc, char const *argv[])
// {

// 	char* txt = "AABAACAADAABAABA";
// 	char* pat = "AABA";

// 	searchAutomata(pat, txt);
// 	// for(int i=0; i<ans.size(); i++)
// 	// {
// 	// 	cout << ans[i] << " ";
// 	// }
// 	// cout << endl;

// 	return 0;
// }

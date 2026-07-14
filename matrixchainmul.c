#include <stdio.h>

// m[][] = Minimum multiplication cost store karega
// s[][] = Kis position pe split hua wo store karega
int m[20][20], s[20][20];

// Recursive function jo optimal parenthesization print karega
void printOrder(int i, int j)
{
    // Agar sirf ek matrix hai to uska naam print karo
    if(i == j)
    {
        printf("A%d", i);
        return;
    }

    // Bracket open
    printf("(");

    // Left side print karo
    printOrder(i, s[i][j]);

    // Right side print karo
    printOrder(s[i][j] + 1, j);

    // Bracket close
    printf(")");
}

int main()
{
    int n;

    // Total matrices input lo
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    // p[] dimensions store karega
    // Agar n matrices hain to dimensions n+1 hongi
    int p[20];

    printf("Enter dimensions:\n");

    // Dimensions input
    for(int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    // Ek matrix ko multiply karne ka cost 0 hota hai
    for(int i = 1; i <= n; i++)
        m[i][i] = 0;

    // Chain length 2 se start hogi
    for(int l = 2; l <= n; l++)
    {
        // Starting matrix choose karo
        for(int i = 1; i <= n-l+1; i++)
        {
            // Ending matrix nikalo
            int j = i+l-1;

            // Initial cost bahut bada rakho
            m[i][j] = 999999;

            // Har possible split try karo
            for(int k = i; k < j; k++)
            {
                // Left Cost
                // +
                // Right Cost
                // +
                // Final multiplication cost

                int q = m[i][k]
                      + m[k+1][j]
                      + p[i-1] * p[k] * p[j];

                // Agar current split ka cost kam hai
                if(q < m[i][j])
                {
                    // Minimum cost update karo
                    m[i][j] = q;

                    // Split position save karo
                    s[i][j] = k;
                }
            }
        }
    }

    // Final minimum multiplication cost
    printf("Minimum Cost = %d\n", m[1][n]);

    // Optimal multiplication order print karo
    printf("Optimal Order = ");

    printOrder(1, n);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numRookCaptures(vector< vector<char> >& board) {
        vector<int> res(4,-1); //l r u d
        vector<int> distance(4,-1); //l r u d
        vector< vector<int> >pos_bishop;
        vector< vector<int> >pos_pawn;
        vector<int> pos_rock;
        char w ;
        for(int i = 0;i <board.size();i++)
        {
            for (int j =0 ;j <sizeof(board[i])/sizeof(char);j++)
            {
                w  = board[i][j];
                if(board[i][j] == 'R')
                {
                    pos_rock.push_back(i);
                    pos_rock.push_back(j);
                }
                else if (board[i][j] == 'p')
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    pos_pawn.push_back(tmp);
                }
                else if (board[i][j] == 'B')
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    pos_bishop.push_back(tmp);
                }
            }
        }

        for(int i = 0;i<pos_bishop.size();i++)
        {
            if(pos_bishop[i][0] == pos_rock[0])
            {
                if(pos_bishop[i][1] > pos_rock[1])
                {
                    int tmp_distance = pos_bishop[i][1] -  pos_rock[1];
                    if(tmp_distance < distance[1] || distance[1] == -1)     //get min distance
                        distance[1] = tmp_distance;
                }
                else
                {
                    int tmp_distance = pos_rock[1] - pos_bishop[i][1];
                    if(tmp_distance < distance[0] || distance[0] == -1)     //get min distance
                        distance[0] = tmp_distance;
                }
            }

            else if(pos_bishop[i][1] == pos_rock[1])
            {
                if(pos_bishop[i][0] > pos_rock[0])
                {
                    int tmp_distance = pos_bishop[i][0] -  pos_rock[0];
                    if(tmp_distance < distance[3] || distance[3] == -1)     //get min distance
                        distance[3] = tmp_distance;
                }
                else
                {
                    int tmp_distance = pos_rock[0] - pos_bishop[i][0];
                    if(tmp_distance < distance[2] || distance[2] == -1)     //get min distance
                        distance[2] = tmp_distance;
                }
            }
        }

        for(int i = 0;i <pos_pawn.size();i++)
        {
            if(pos_pawn[i][0] == pos_rock[0])
                if(pos_pawn[i][1] > pos_rock[1])
                {
                    if((pos_pawn[i][1] - pos_rock[1]) < distance[0] || distance[0] == -1)
                        res[0] = 1;
                }
                else if(pos_pawn[i][1] < pos_rock[1])
                {
                    if(( pos_rock[1] - pos_pawn[i][1]) < distance[1] || distance[1] == -1)
                        res[1] = 1;
                }
            else if(pos_pawn[i][1] == pos_rock[1])
                {
                    if(pos_pawn[i][0] > pos_rock[0])
                    {
                        if((pos_pawn[i][0] - pos_rock[0]) < distance[3] || distance[3] == -1)
                            res[3] = 1;
                    }
                    else if(pos_pawn[i][0] < pos_rock[0])
                    {
                        if(( pos_rock[0] - pos_pawn[i][0]) < distance[2] || distance[2] == -1)
                            res[2] = 1;
                    }
            }
        }


        cout <<"finished"<<endl;
    }
};


int main()
{
//    cout << 'Hello World!' << endl;

//    char board[][8] = {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','R','.','.','.','p'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}}; //cannot use ""
    char board[][8] = {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'p','p','.','R','.','p','B','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','B','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'}};
    int len = sizeof(board) / sizeof(char);
    int len_col = sizeof(board[0])/sizeof(char);
    int len_row = len / len_col;

    vector< vector<char> > v_board;
    for(int i = 0;i < len_row;i++)
    {
        vector<char> v_col(board[i],board[i]+ len_col);
        v_board.push_back(v_col);
    }

    Solution test;
    test.numRookCaptures(v_board);
    return 0;
}


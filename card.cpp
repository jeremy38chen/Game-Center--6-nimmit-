//
//  card.cpp
//  
//
//  Created by Jeremy on 3/27/16.
//
//

#include <iostream>
#include <cstdlib>
#include <iomanip>


#define MaxNumCard 100 //一人最多100張卡
#define MaxNumPlayer 100//最多100名玩家

using namespace std;


class background
{
    private:
    int checkcard[1005];//檢查是否發到同樣的牌
    int rest_card[4][100];//rest_card[1][1]第一row 第一張牌
    static int row_1_endcard ;//計算各列現在第幾章牌
    static int row_2_endcard ;
    static int row_3_endcard ;
    static int row_4_endcard ;
    
    public:
    
    background(){
        for (int i=1; i<5; i++) {
            for (int j =1; j<101; j++) {
                rest_card[i][j]=0;
            }
        };
    };
    //看要幾個玩家
    int setPlayer(){
    
        int totalplayer=0;
        cout << "Enter the number of players who want to play:\n";
        cin >> totalplayer;
        cout << "totalplayer:"<< totalplayer<<endl;
        return totalplayer;

    }
    //輸入玩家人數，卡片矩陣[玩家人數][假設最大ㄧ人張數100張]，剩下卡片矩陣
    void setCard(int totalplayer,int card[][MaxNumCard]){
        int numcard=1;//card[1][1]代表player 1，第一張牌
        int numplayer=1;
        int numrand=0;
        int i=1;
        
        while(1){
            card[numplayer][numcard]=numrand=rand()%(totalplayer*10+4)+1;
            if(checkcard[numrand]==1){continue;};
            checkcard[numrand]=1;//發過等於1
            numcard++;
            if(numcard==11){numcard=1;numplayer++;}
            if(numplayer==totalplayer+1){//如過玩家發完牌，換牌面的四張
                while (1) {
                    rest_card[i][1]=numrand=rand()%(totalplayer*10+4)+1;
                    if(checkcard[numrand]==1){continue;};
                    checkcard[numrand]=1;//發過等於1
                    i++;
                    if (i==5)break;//發到第五張停
                }
            break;}
        }
    
    }
    //顯示牌面
    void ShowCard(){
        
        cout << "\tTable:\n" <<endl;
        
        ///////////////////////ROW 1////////////////////////////////////
        cout << " \t\t\t";
        for (int i =1; i<row_1_endcard+1; i++) cout << "----- ";
        cout << " \n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_1_endcard+1; i++) {
            if((rest_card[1][i]/10) !=0)cout << "|"<< rest_card[1][i]<<" | ";//給兩位數以上
            if((rest_card[1][i]/10) ==0)cout << "|"<< rest_card[1][i]<<"  | ";//給個位數
        }
        cout << " \n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_1_endcard+1; i++) cout << "|   | ";
        cout << " \n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_1_endcard+1; i++) cout << "----- ";
        cout << " \n\n";
        
        ///////////////////////ROW 2///////////////////////////////////////
        
        cout << " \t\t\t";
        for (int i =1; i<row_2_endcard+1; i++) cout << "----- ";
        cout << "\n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_2_endcard+1; i++) {
            if((rest_card[2][i]/10) !=0)cout << "|"<< rest_card[2][i]<<" | ";//給兩位數以上
            if((rest_card[2][i]/10) ==0)cout << "|"<< rest_card[2][i]<<"  | ";//給個位數
        }
        cout << " \n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_2_endcard+1; i++) cout << "|   | ";
        cout << " \n";
        
        cout << " \t\t\t";
        for (int i =1; i<row_2_endcard+1; i++) cout << "----- ";
        cout << " \n\n";
        
    
        ////////////////////////ROW 3//////////////////////////////////////
    
        cout << " \t\t\t";
        for (int i =1; i<row_3_endcard+1; i++) cout << "----- ";
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_3_endcard+1; i++) {
            if((rest_card[3][i]/10) !=0)cout << "|"<< rest_card[3][i]<<" | ";//給兩位數以上
            if((rest_card[3][i]/10) ==0)cout << "|"<< rest_card[3][i]<<"  | ";//給個位數
        }
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_3_endcard+1; i++) cout << "|   | ";
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_3_endcard+1; i++) cout << "----- ";
        cout << " \n\n";
    
        ////////////////////////ROW 4//////////////////////////////////////
    
        cout << " \t\t\t";
        for (int i =1; i<row_4_endcard+1; i++) cout << "----- ";
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_4_endcard+1; i++) {
            if((rest_card[4][i]/10) !=0)cout << "|"<< rest_card[4][i]<<" | ";//給兩位數以上
            if((rest_card[4][i]/10) ==0)cout << "|"<< rest_card[4][i]<<"  | ";//給個位數
        }
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_4_endcard+1; i++) cout << "|   | ";
        cout << " \n";
    
        cout << " \t\t\t";
        for (int i =1; i<row_4_endcard+1; i++) cout << "----- ";
        cout << " \n\n";
    
        //////////////////////////////////////////////////////////////////////
    
    }
    //顯示各玩家選牌後，經過排序後的畫面
    void ShowCardOrder(int totalplayer,int card_order[],int player_order[]){
    
        cout << "\n\n";
        cout << "\tCard order: " <<endl;
        cout << "\t\t\t";
        for (int i =1; i<totalplayer+1; i++) {cout << "----- ";};
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<totalplayer+1; i++) {
            if((card_order[i]/10) !=0)cout << "|"<< card_order[i]<<" | ";//給兩位數以上
            if((card_order[i]/10) ==0)cout << "|"<< card_order[i]<<"  | ";//給個位數
        }
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<totalplayer+1; i++) {cout << "|   | ";}
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<totalplayer+1; i++) {cout << "----- ";}
        cout << "\n";
        cout << "\t\t\t";
        for (int i =1; i<60; i++) {cout << "-";}
        cout << "\n";
        cout << " Card belong to Player: ";
        for (int i =1; i<totalplayer+1; i++) {
            cout << "  "<<player_order[i]<<"   ";
        }
        cout << "\n\n";
    
    }
    //顯示玩家現在的分數
    void ShowPlayerPoint(int totalplayer,int player_point[]){
        
        cout << "Player:\t" ;
        for (int i = 1; i < totalplayer+1; i++) {
            cout << i << "\t";
        }
        cout << "\n\t";
        for(int i = 1; i< 80;i++)cout << "-";
        cout << "\n";
        cout << "Point: \t" ;
        for (int i = 1; i < totalplayer+1; i++) {
            cout << player_point[i] << "\t";
        }
        cout << "\n\n";
    
    }
    //玩家總數，出排順序的卡片，出排順序的玩家，存玩家分數
    void Determine(int totalplayer,int card_order[],int player_order[],int player_point[]){
    
        int min_different =0,temp_CurrentRow,temp_different=0,choice,a=1;
        //存放最小卡片差異      //現在暫存的列    //現在暫存的差異
        
        for (int i = 1; i<totalplayer+1; i++) {
        
            min_different =0;
            temp_CurrentRow =0;
            temp_different = (card_order[i]-rest_card[1][row_1_endcard]);
            if (temp_different>0) {
                if (row_1_endcard==5) {
                    a=1;
                    while (1) {
                        player_point[player_order[i]] = player_point[player_order[i]]+a;
                        a++;
                        if (a==6) {
                            break;
                        }
                    }
                    row_1_endcard =1;
                    min_different =0;
                    rest_card[1][1] = card_order[i];
                }else{
                
                    min_different  = temp_different;
                    temp_CurrentRow = 1;
                
                }
            }
            temp_different = (card_order[i]-rest_card[2][row_2_endcard]);
            if ((min_different > temp_different || min_different==0 )&& temp_different>0) {
                if (row_2_endcard==5) {
                    a=1;
                    while (1) {
                        player_point[player_order[i]] = player_point[player_order[i]]+a;
                        a++;
                        if (a==6) {
                            break;
                        }
                    }
                    row_2_endcard =1;
                    min_different =0;
                    rest_card[2][1] = card_order[i];
                }else{
            
                    min_different  = temp_different;
                    temp_CurrentRow = 2;
            
                }
            }
            temp_different = (card_order[i]-rest_card[3][row_3_endcard]);
            if ((min_different > temp_different || min_different==0) && temp_different>0) {
                if (row_3_endcard==5) {
                    a=1;
                    while (1) {
                        player_point[player_order[i]] = player_point[player_order[i]]+a;
                        a++;
                        if (a==6) {
                            break;
                        }
                    }
                    row_3_endcard =1;
                    min_different =0;
                    rest_card[3][1] = card_order[i];
                }else{
                
                    min_different  = temp_different;
                    temp_CurrentRow = 3;
            
                }
            }
            temp_different = (card_order[i]-rest_card[4][row_4_endcard]);
            if ((min_different > temp_different || min_different==0) && temp_different>0) {
                if (row_4_endcard==5) {
                    a=1;
                    while (1) {
                        player_point[player_order[i]] = player_point[player_order[i]]+a;
                        a++;
                        if (a==6) {
                            break;
                        }
                    }
                    row_4_endcard =1;
                    min_different =0;
                    rest_card[4][1] = card_order[i];
                }else{
            
                    min_different  = temp_different;
                    temp_CurrentRow = 4;
            
                }
            }
            if (temp_CurrentRow ==1) {row_1_endcard++;rest_card[1][row_1_endcard] = card_order[i];}//符合row1
            if (temp_CurrentRow ==2) {row_2_endcard++;rest_card[2][row_2_endcard] = card_order[i];}//符合row2
            if (temp_CurrentRow ==3) {row_3_endcard++;rest_card[3][row_3_endcard] = card_order[i];}//符合row3
            if (temp_CurrentRow ==4) {row_4_endcard++;rest_card[4][row_4_endcard] = card_order[i];}//符合row4
            //都比個row小的話
            if (temp_CurrentRow ==0) {
                a=1;
                choice = getChoice(player_order[i]);
                while (1) {
                    player_point[player_order[i]] = player_point[player_order[i]]+a;
                        if (choice==1 && row_1_endcard==a) {row_1_endcard=1;break;};
                        if (choice==2 && row_2_endcard==a) {row_2_endcard=1;break;};
                        if (choice==3 && row_3_endcard==a) {row_3_endcard=1;break;};
                        if (choice==4 && row_4_endcard==a) {row_4_endcard=1;break;};
                    a++;
                }
                rest_card[choice][1] = card_order[i];
            }
    
        }
    }
    //比牌面小的話，玩家要拿走哪ㄧrow
    int getChoice(int player_order){
        
        int choice =0;
        cout << "\nFor Player: "<< player_order <<"\nEnter your choice(number of table row 1,2,3 or 4) to eliminate:" << endl;
        cin  >> choice ;
        return choice;
        
    }
    //玩家選牌後，排序
    void sort(int totalplayer,int card_order[],int player_order[]){
        
        int temp_card,temp_player;
        for(int i=1;i<(totalplayer+1);i++)//采用一般的冒泡排序方法
            for(int j=1;j<(totalplayer+1)-i;j++)
                if(card_order[j]>card_order[j+1])
                {
                    temp_card=card_order[j];
                    temp_player=player_order[j];
                    card_order[j]=card_order[j+1];
                    player_order[j]=player_order[j+1];
                    card_order[j+1]=temp_card;
                    player_order[j+1]=temp_player;
                    
                }
    
    }
    


};


class player
{
    private:
    


    public:
    
   int getChoice(){
        
        int choice =0;
        cout << "Enter your choice\n(the number of the order of our card//NOT THE POINT OF OUR CARD!):" << endl;
        cin  >> choice ;
        return choice;
    
    }
    //出牌後，自己牌排序
    void ArrangeCard(int player,int choice,int card[][MaxNumCard]){
        
        int i=0;
        while (1) {
            card[player][choice+i] = card[player][choice+i+1];
            if (card[player][choice+i+1]==0)break;
            i++;
        }
    
    
    }
    //顯示自己的牌組
    void ShowCard(int player,int card[][MaxNumCard]){
        
        cout << "\n\n";
        cout << "\tCard of Player " << player << endl;
        cout << "\t\t\t";
        for (int i =1; i<11; i++) {if(card[player][i]==0)break;cout << "----- ";};
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<11; i++) {
            if(card[player][i]==0)break;
            if((card[player][i]/10) !=0)cout << "|"<< card[player][i]<<" | ";//給兩位數以上
            if((card[player][i]/10) ==0)cout << "|"<< card[player][i]<<"  | ";//給個位數
        }
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<11; i++) {if(card[player][i]==0)break;cout << "|   | ";}
        cout << "\n";
        
        cout << "\t\t\t";
        for (int i =1; i<11; i++) {if(card[player][i]==0)break;cout << "----- ";}
        cout << "\n\n";
        
    }
    
    




    
};
//初始化個row
int background ::row_1_endcard =1;
int background ::row_2_endcard =1;
int background ::row_3_endcard =1;
int background ::row_4_endcard =1;

int main(){
    
    int card[MaxNumPlayer][MaxNumCard]={0},rest_card[4]={0},card_order[MaxNumCard]={0},player_order[MaxNumPlayer]={0},choice,player_point[MaxNumPlayer];
    //int Mininum;
    static int totalplayer;
    int Mininum;
    
    background b;
    player p;
    
    totalplayer = b.setPlayer();
    b.setCard(totalplayer,card);
    
    b.ShowCard();
    b.ShowPlayerPoint(totalplayer,player_point);
    
    for (int count=0; count<10; count++) {
        
        for (int i=1; i<totalplayer+1 ; i++) {
            
            p.ShowCard(i,card);
            
            choice = p.getChoice();
            card_order[i] = card[i][choice];
            player_order[i] = i;
            
            p.ArrangeCard(i,choice,card);
            
        }
    
        b.sort(totalplayer,card_order,player_order);
        b.ShowCardOrder(totalplayer,card_order,player_order);
        b.Determine(totalplayer,card_order,player_order,player_point);
        b.ShowCard();
        b.ShowPlayerPoint(totalplayer,player_point);
        
    }
    for (int i = 2; i<totalplayer+1; i++) {
        (player_point[1] < player_point[i]) ? Mininum = player_point[1] : Mininum = player_point[i];
    }
    
    cout << player_point[1] << endl;
    cout << player_point[2] << endl;
    cout << Mininum << endl;
    if (player_point[1]==Mininum) {
        cout << "YOU WIN!!!" << endl;
    }else{
        cout << "YOU LOSE!!" << endl;
    }
    
    return EXIT_SUCCESS;

}


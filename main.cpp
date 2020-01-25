#include<iostream>
#include<string>
using namespace std;

#define gridSize 3

class Game{

	private:
		char grid[gridSize][gridSize];

	public:
	   void draw_grid()
	   {
		   int n = 1;

			for(int x = 0; x < gridSize; x++)
				{
					for(int y = 0; y < gridSize; y++)
						{
							grid[x][y] = to_string(n).c_str()[0];
								n++;
						} 
				}
	   }

	   void show_grid()
	   {

	    	printf("___________\n");
			for(int x = 0; x < gridSize; x++)
				{
					for(int y = 0; y < gridSize; y++)
						{
							printf(" %c |", grid[x][y]);
						} 
					printf("\n___________\n");
				}
		}

		void player1_turn()
		{
			string input;

			while (true)
			{
				puts("Player-1");
				puts("Which position would you choose?");
				getline(cin, input);
				char position_entered = input.c_str()[0];
				cout<<"You entered "<<position_entered<<endl;

				int entered_number = position_entered - '0'; // converting char to int form
				int index = entered_number - 1; 

				int row = index / gridSize;
				int col = index % gridSize;
				char grid_positon = grid[row][col];

				if (grid_positon == 'X' || grid_positon == 'O')
				{
					puts("This grid position is already taken!!");
				}
				else
				{
					grid[row][col] = 'X';
					break;
				}
				
			}
			
		}

		void player2_turn()
		{
			string input;

			while (true)
			{
				puts("Player-2");
				puts("Which position would you choose?");
				getline(cin, input);
				char position_entered = input.c_str()[0];
				cout<<"You entered "<<position_entered<<endl;

				int entered_number = position_entered - '0'; // converting char to int form
				int index = entered_number - 1; 

				int row = index / gridSize;
				int col = index % gridSize;
				char grid_positon = grid[row][col];

				if (grid_positon == 'X' || grid_positon == 'O')
				{
					puts("This grid position is already taken!!");
				}
				else
				{
					grid[row][col] = 'O';
					break;
				}
				
			}
		}

		void check_win()
		{
			const char* winningCombinantions[8] = {
				"123", 
				"456",
				"789",
				"147",
				"258",
				"369",
				"159",
				"357"
			};

			//Looping through possible winning combinations.
			for(int i = 0; i < 8; i++)
			{
				bool winner = true;
				char previousGrid = '0';
				const char* winningCombination = winningCombinantions[i];

				for(int index = 0; index < 3; index++)
				{
					char position = winningCombination[index];

					int positionNum = position - '0'; 
					int gridSpace = positionNum - 1;

					int row = gridSpace / gridSize;
					int col = gridSpace % gridSize;

					char gridChar = grid[row ][col];

					if(previousGrid == '0')
					{
						previousGrid = gridChar;
					}
				    else if(previousGrid == gridChar)
					{
						continue;
					}
					else
					{
						winner = false;
						break;
					}
						
				}
				if (winner)
				{
					puts("Sugoi desu!! (/^ω^)/ We have a winner!!!");
					printf("%c won, congrats!!!\n", previousGrid);
					show_grid();

					exit(0);
					break;
				}
			}


		}

		Game(){
			draw_grid();


			show_grid();
			check_win();
			while (true)
			{
				player1_turn();
				check_win();
				show_grid();

				player2_turn();
				show_grid();
				check_win();
			}

	}
};

int main(int argc, char *argv[])
{
	
	Game game;
	return 0;
}

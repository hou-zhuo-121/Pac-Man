#include"ghost3.h"
#include<cmath>
int ghost3(int g_map_x, int g_map_y, int p_map_x, int p_map_y, int* speed, int* form, int* last_step_x, int* last_step_y, int last_derection)
{
	int map1[20][20] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0},
						 {0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0},
						 {0,1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0},
						 {0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,0},
						 {0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
						 {0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
						 {0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
						 {0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0},
						 {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0},
						 {0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0},
						 {0,1,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,1,1,0},
						 {0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0},
						 {0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0},
						 {0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0},
						 {0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0},
						 {0,1,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0},
						 {0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
						 {0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	
	int map2[20][20] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,9,9,9,9,9,9,9,9,0,0,0,0,0,0,1,1,1,1,0},
						 {0,9,0,1,0,0,0,0,9,0,0,0,0,0,0,1,0,0,1,0},
						 {0,9,0,1,0,0,0,0,9,9,9,9,9,9,9,9,9,0,1,0},
						 {0,9,0,1,1,1,1,1,1,0,0,1,0,0,0,0,9,1,1,0},
						 {0,9,0,1,0,0,0,0,1,0,0,1,0,0,0,0,9,0,0,0},
						 {0,9,1,1,0,0,0,0,1,1,1,1,1,1,1,1,9,0,0,0},
						 {0,9,0,0,0,0,0,0,1,0,0,1,0,0,0,0,9,0,0,0},
						 {0,9,0,0,0,0,1,1,1,0,0,1,0,0,0,0,9,0,0,0},
						 {0,9,1,1,1,1,1,0,1,1,1,1,1,1,1,1,9,0,0,0},
						 {0,9,0,1,0,0,1,0,0,1,0,1,0,0,0,0,9,0,0,0},
						 {0,9,0,1,0,0,1,1,1,1,0,1,0,0,0,0,9,9,9,0},
						 {0,9,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,9,0},
						 {0,9,9,9,0,0,0,0,0,0,0,1,0,0,0,0,0,0,9,0},
						 {0,0,0,9,0,0,0,0,1,1,1,1,1,1,1,0,0,0,9,0},
						 {0,1,1,9,0,0,0,0,1,0,0,0,0,0,1,0,0,0,9,0},
						 {0,1,0,9,9,9,9,9,9,0,0,0,0,0,9,9,9,9,9,0},
						 {0,1,0,0,1,0,0,0,9,0,0,0,0,0,9,0,0,0,0,0},
						 {0,1,1,1,1,0,0,0,9,9,9,9,9,9,9,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	int derection = 0, now_step_x = 0, now_step_y = 0;
	if(abs(p_map_x-g_map_x)+abs(p_map_y-g_map_y)<=6)
	{
		int trace[400][3];
		int k = 0, l = 0;
		trace[k][0] = g_map_x;
		trace[k][1] = g_map_y;
		trace[k][2] = 0;
		int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
		int pc = 0, pre = -1;
		map1[g_map_y][g_map_x] = 2;
		while (trace[k][0] != p_map_x || trace[k][1] != p_map_y)
		{
			if (pc == 0)
				pre++;
			if (map1[trace[pre][1] + dy[pc]][trace[pre][0] + dx[pc]] == 1)
			{
				k++;
				trace[k][0] = trace[pre][0] + dx[pc];
				trace[k][1] = trace[pre][1] + dy[pc];
				trace[k][2] = pre;
				map1[trace[pre][1] + dy[pc]][trace[pre][0] + dx[pc]] = 2;
			}
			pc = (pc + 1) % 4;
		}
		while (trace[k][2] != 0)
			k = trace[k][2];
		if ((g_map_x) < trace[k][0])
			derection = 0;
		if ((g_map_x) > trace[k][0])
			derection = 2;
		if ((g_map_y) > trace[k][1])
			derection = 1;
		if ((g_map_y) < trace[k][1])
			derection = 3;
		if(map2[g_map_y][g_map_x] == 9)
		{
			now_step_x = g_map_x;
			now_step_y = g_map_y;
		}
		*speed = 3;
		*form = 1;
	}
	else
	{
		if(map2[g_map_y][g_map_x]==9)
		{
			if(last_step_x==0&&last_step_y==0)
			{
				switch(last_derection)
				{
				case 0:
					derection = 3;
					break;
				case 1:
					derection = 0;
					break;
				case 2:
					derection = 1;
					break;
				case 3:
					derection = 2;
					break;
				}
			}
			else
			{
				map2[*last_step_y][*last_step_x] = 2;
				int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, next_step_x = 0, next_step_y = 0;
				for (int i = 0; i < 4; i++)
				{
					if (map2[g_map_y + dy[i]][g_map_x + dx[i]] == 9)
					{
						next_step_x = g_map_x + dx[i];
						next_step_y = g_map_y + dy[i];
					}
				}
				if ((g_map_x) < next_step_x)
					derection = 0;
				if ((g_map_x) > next_step_x)
					derection = 2;
				if ((g_map_y) > next_step_y)
					derection = 1;
				if ((g_map_y) < next_step_y)
					derection = 3;
			}
			now_step_x = g_map_x;
			now_step_y = g_map_y;
		}
		else
		{
			int trace[400][3];
			int k = 0, l = 0;
			trace[k][0] = g_map_x;
			trace[k][1] = g_map_y;
			trace[k][2] = 0;
			int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
			int pc = 0, pre = -1;
			map2[g_map_y][g_map_x] = 2;
			while (true)
			{
				if (pc == 0)
					pre++;
				if (map2[trace[pre][1] + dy[pc]][trace[pre][0] + dx[pc]] == 1|| map2[trace[pre][1] + dy[pc]][trace[pre][0] + dx[pc]] == 9)
				{
					k++;
					trace[k][0] = trace[pre][0] + dx[pc];
					trace[k][1] = trace[pre][1] + dy[pc];
					trace[k][2] = pre;
					if (map2[trace[k][1]][trace[k][0]] == 9)
						break;
					map2[trace[pre][1] + dy[pc]][trace[pre][0] + dx[pc]] = 2;
				}
				pc = (pc + 1) % 4;
			}
			while (trace[k][2] != 0)
				k = trace[k][2];
			if ((g_map_x) < trace[k][0])
				derection = 0;
			if ((g_map_x) > trace[k][0])
				derection = 2;
			if ((g_map_y) > trace[k][1])
				derection = 1;
			if ((g_map_y) < trace[k][1])
				derection = 3;
		}
		*speed = 1;
		*form = 0;
	}
	*last_step_x = now_step_x;
	*last_step_y = now_step_y;
	return derection;
}
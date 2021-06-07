class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> res (num_people, 0);
		int c = 1;
		while(candies > 0){
			for(int i = 0; i < num_people; i++){
				if(candies >= c){
					res[i] += c;
					candies -= c;
					c++;
				}
				else{
					res[i] += candies;
					candies = 0;
					break;
				}
			}
		}
		return res;
	}
};
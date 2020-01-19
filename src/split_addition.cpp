#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

int get_input_and_convert_to_int ();
void print_individual_additions(int num1, int num2);
std::string convert_to_binary(int a);
void print_final_result_as_hex(int num1, int num2);

#ifndef MARMOSET_TESTING
int main(){
	int num1=0;
	int num2=0;
	bool value=true;

	while (value){
		num1=get_input_and_convert_to_int();
		if (num1==-1){
			break;
		}
		num2=get_input_and_convert_to_int();
		if (num2==-1){
			break;
		}
		print_individual_additions(num1, num2);
	}

	return 0;
}
#endif

int get_input_and_convert_to_int (){
	int x=0;
	char ch;
	std::cout<<"Enter a Hexadecimal Number"<<std::endl;
	for (int i=0;i<4;i++){
		std::cin>>ch;
		x=x<<4*(i>0);
		if (ch=='Q'){
			return -1;
		}
		else if (ch>='A'&&ch<='F'){
			x+=10+ch-'A';
		}
		else if (ch>='0'&&ch<='9'){
			x+=ch-'0';
		}
	}
	return x;
}
std::string convert_to_binary(int a){
	std::string bin;
	for (int i=7;i>=0;i--){
		if (((a>>i)&1)==1){
			bin+="1";
		}
		else {
			bin+="0";
		}
	}
	if ((a>>7) >1){
		bin +=" overflow";
	}
	return bin;

}
void print_individual_additions(int num1, int num2){
	int num1_first;
	int num2_first;
	int num1_last;
	int num2_last;
	num1_first=num1>>8;
	num2_first=num2>>8;
	num1_last=255&num1;
	num2_last=255&num2;

	int first_addition;
	first_addition= num1_first +num2_first;

	int last_addition;
	last_addition= num1_last +num2_last;

	std::cout<<convert_to_binary(num1_first)<<" + "<<convert_to_binary(num2_first)<<" = "<<convert_to_binary(first_addition)<<std::endl;
	std::cout<<convert_to_binary(num1_last)<<" + "<<convert_to_binary(num2_last)<<" = "<<convert_to_binary(last_addition)<<std::endl;
	print_final_result_as_hex(first_addition, last_addition);

}
void print_final_result_as_hex(int num1, int num2){
	bool over=false;
	std::cout<<"Final Result: "<<std::endl;
	if ((num2>>7)>1){
		num1+=1;
		over=true;
	}
	num1=num1-(num1>>8<<8);
	if ((num1>>7)>1){
		over=true;
	}
	num2=num2-(num2>>8<<8);
	if ((num1>>4)==0){
		std::cout<<0;
	}
	std::cout<<std::hex<<std::uppercase<<num1;
	if ((num2>>4)==0){
		std::cout<<0;
	}
	std::cout<<std::hex<<std::uppercase<<num2;

	if (over){
		std::cout<<" overflow";
	}

	std::cout<<std::endl;
}

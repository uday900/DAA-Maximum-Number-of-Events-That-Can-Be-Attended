int maxEvents(int** events, int eventsSize, int* eventsColSize){
    int i,j,temp,temp2,big;
    if(eventsSize==1){
        return events[0][0];
    }
    else{
    for(i=0;i<eventsSize-1;i++){
        for(j=i+1;j<eventsSize;j++){
            if(events[i][1]>events[j][1]){
                temp=events[i][0]; temp2=events[i][1];
                events[i][0]=events[j][0];
                events[i][1]=events[j][1];
                events[j][0]=temp;
                events[j][1]=temp2;
            }
            else if(events[i][1]==events[j][1] && events[i][0]>events[j][0]){  
                temp=events[i][0]; temp2=events[i][1];
                events[i][0]=events[j][0];
                events[i][1]=events[j][1];
                events[j][0]=temp;
                events[j][1]=temp2;
            }
            else{
                big=events[j][1];
            }
        }
    }
    }
    int days[big+1],count=0;
    for(int i=0;i<big+1;i++){
        days[i]=0;
    }
    int event=0;
    for(i=0;i<eventsSize;i++){
        int k=events[i][0];
        event++;
        if(days[k]==0){
            days[k]=event;
            count++;
        }
        else{
            int start=1+events[i][0];
            int end=events[i][1];
            while(start<=end){
            	if(days[start]==0){
            		days[start]=event;
                    count++;
            		break;
				}else start++;
			}
        }
    }
    return count;
}

void bin_img(unsigned char *ptr, int w, int h, unsigned char limiar)
{
	
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
		
			if(ptr[i*w + j] < limiar){
				ptr[i*w + j] = 0;
			}
			else{
				ptr[i*w + j] = 255;
			}
		
		}
	}
}
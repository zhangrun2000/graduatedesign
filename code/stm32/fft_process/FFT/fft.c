#include "fft.h"

static float32_t fft_inputbuf[FFT_LENGTH * 2];
static float32_t fft_outputbuf[FFT_LENGTH];
static double range_test;
static uint32_t max_x_test;
static double gap_test;
static uint32_t time_test1;
static uint32_t time_test2;
static uint32_t time_test3;
static uint32_t time_test4;

void fft_start()
{
	arm_cfft_radix4_instance_f32 scfft;
	arm_cfft_radix4_init_f32(&scfft, FFT_LENGTH, 0, 1);

	int16_t temp_buf;
    for (int32_t i = 0; i < FFT_LENGTH; i++)
    {
        if(i < 600)
        {
        	temp_buf = UserRxBufferFS[2 * i]|(UserRxBufferFS[2 * i + 1] << 8);
            fft_inputbuf[2 * i]     = (float32_t)(temp_buf);
            fft_inputbuf[2 * i + 1] = 0;
        }
        else
        {
            fft_inputbuf[2 * i]     = 0;
            fft_inputbuf[2 * i + 1] = 0;
        }
    }
    TIM2->CNT = 0;
    arm_cfft_radix4_f32(&scfft, fft_inputbuf);
    time_test1 =  TIM2->CNT;
    arm_cmplx_mag_f32(fft_inputbuf, fft_outputbuf, FFT_LENGTH);
    time_test2 =  TIM2->CNT;
    caculate_range();
    time_test3 =  TIM2->CNT;
}

uint32_t find_fft_max()
{
	float32_t max = 0;
	uint32_t  max_x;
	for (int32_t i = 0; i < FFT_LENGTH/2; i++)
	{
		if(max < fft_outputbuf[i])
		{
			max = fft_outputbuf[i];
			max_x = i;
		}
	}
	return max_x;
}

double caculate_range()
{
	uint32_t max_x = find_fft_max();
	max_x_test = max_x;
	gap_test = gap;
	double range = (max_x * gap);
	range_test = range;
	return range;
}




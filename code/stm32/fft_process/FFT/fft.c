#include "fft.h"
#include "arm_math.h"
float32_t fft_inputbuf[FFT_LENGTH * 2];
float32_t fft_outputbuf[FFT_LENGTH];

/*
void fft_start()
{
	arm_cfft_radix4_instance_f32 scfft;
	arm_cfft_radix4_init_f32(&scfft, FFT_LENGTH, 0, 1);
    for (int32_t i = 0; i < FFT_LENGTH; i++)
    {
        if(i < 1200)
        {
            fft_inputbuf[2 * i]     = *(float32_t *)(UserRxBufferFS + 2 * i);
            fft_inputbuf[2 * i + 1] = 0;
        }
        else
        {
            fft_inputbuf[2 * i]     = 0;
            fft_inputbuf[2 * i + 1] = 0;
        }
    }

    arm_cfft_radix4_f32(&scfft, fft_inputbuf);
    arm_cmplx_mag_f32(fft_inputbuf, fft_outputbuf, FFT_LENGTH);
}

*/

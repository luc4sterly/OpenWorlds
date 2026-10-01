// 0041fc13 FUN_0041fc13 [Global]
// program: sfmain.exe

void FUN_0041fc13(void)

{
  undefined4 in_EAX;
  
  if ((int)DAT_00462394 < (int)DAT_00462398) {
    FUN_004296b9(s_newInputLength__d_too_high__Set_t_00436abf);
    DAT_00462398 = DAT_00462394;
  }
  if (DAT_0046255c != (LPWAVEHDR)0x0) {
    DAT_0046255c->dwBufferLength = DAT_00462398;
    waveInAddBuffer(DAT_0043d514,DAT_0046255c,0x20);
  }
  DAT_0046255c = (LPWAVEHDR)in_EAX;
  return;
}



// 0042f3b0 FUN_0042f3b0 [Global]
// program: gamma.dll

void * __cdecl FUN_0042f3b0(void *param_1,int param_2)

{
  char *pcVar1;
  byte local_115;
  undefined **local_114;
  char local_110 [256];
  
  FUN_0042f460(param_1,&local_115,1);
  pcVar1 = (char *)FUN_00450b60(local_115 + 1);
  FUN_0042f460(param_1,pcVar1,(uint)local_115);
  pcVar1[local_115] = '\0';
  FUN_00427410(&local_114,pcVar1,0xff);
  FUN_0044d6d0((char *)(param_2 + 4),local_110,0xff);
  *(undefined1 *)(param_2 + 0x103) = 0;
  local_114 = &PTR_LAB_00471ff8;
  FUN_00451780((undefined4 *)pcVar1);
  return param_1;
}



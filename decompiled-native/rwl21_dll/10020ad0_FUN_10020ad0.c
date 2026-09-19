// 10020ad0 FUN_10020ad0 [Global]
// programa: RWL21.DLL

int FUN_10020ad0(FILE *param_1,undefined4 param_2)

{
  int iVar1;
  char local_100 [256];
  
  iVar1 = FUN_100206d0(param_1,local_100,0x100);
  if ((iVar1 == 1) && (local_100[0] != '#')) {
    iVar1 = _sscanf(local_100,&DAT_1005ab48,param_2);
    return iVar1;
  }
  return 0;
}



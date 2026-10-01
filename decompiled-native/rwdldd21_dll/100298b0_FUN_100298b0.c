// 100298b0 FUN_100298b0 [Global]
// program: RWDLDD21.DLL

bool FUN_100298b0(byte *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 *param_6,uint param_7)

{
  int iVar1;
  
  iVar1 = FUN_10028780(param_1,param_2,param_4,param_6,param_7);
  if (iVar1 == 0) {
    return false;
  }
  iVar1 = FUN_10028b30((int)param_1,param_2,param_3,param_5,(int)param_6,param_7);
  return (bool)('\x01' - (iVar1 == 0));
}



// 0041e240 FUN_0041e240 [Global]
// program: gamma.dll

int __cdecl FUN_0041e240(int param_1,uint param_2,int param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  undefined1 local_a20 [2560];
  uint local_20 [5];
  
  iVar3 = 0;
  pfVar2 = (float *)(param_2 + param_3);
  if (param_1 == 0) {
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[4] = 0;
    local_20[3] = 0;
    iVar3 = FUN_0041cea0(&param_2,pfVar2,(int)local_a20,local_20);
  }
  else if (param_1 == 1) {
    iVar3 = FUN_00418f90();
    if (iVar3 == 0) {
      FUN_00402800(s_nShape_00470970,0x40e);
    }
    iVar1 = FUN_0041d950(iVar3,&param_2,(uint3 *)pfVar2);
    if (iVar1 != 0) {
      FUN_004190d0(iVar3);
      iVar3 = 0;
    }
  }
  return iVar3;
}



// 00426930 FUN_00426930 [Global]
// program: gamma.dll

int __cdecl FUN_00426930(byte *param_1,int param_2,int param_3,int param_4,undefined1 *param_5)

{
  byte *pbVar1;
  int iVar2;
  int local_410 [256];
  
  pbVar1 = param_5 + 0x100;
  if (param_2 != 0) {
    FUN_00426640(param_1,param_2,param_3,param_4,(undefined4 *)pbVar1);
    iVar2 = FUN_004266f0(pbVar1,local_410);
    if (0 < iVar2) {
      FUN_00426820((char *)pbVar1,iVar2,local_410,param_5);
    }
    return iVar2;
  }
  FUN_00402800(s_huffdcod_00471cb0,0xad);
  return 0;
}



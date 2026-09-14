// 00426640 FUN_00426640 [Global]
// programa: gamma.dll

void __cdecl FUN_00426640(byte *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0x40;
  puVar2 = param_5;
  do {
    iVar3 = iVar3 + -1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  if ((int)((param_4 + 2) - (uint)(param_4 + 1U < 0x80000000)) >> 1 < param_2) {
    FUN_00402800(s_huffdcod_00471cb0,0x28);
  }
  iVar3 = param_2 * 2;
  if (param_4 < param_2 * 2) {
    iVar3 = param_4;
  }
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      *(byte *)((int)param_5 + (uint)*(byte *)(param_3 + iVar4)) = bVar1 & 0xf;
      if (iVar4 + 1 < iVar3) {
        *(char *)((int)param_5 + (uint)*(byte *)(param_3 + iVar4 + 1)) =
             (char)((int)(uint)bVar1 >> 4);
      }
      iVar4 = iVar4 + 2;
    } while (iVar4 < iVar3);
  }
  return;
}



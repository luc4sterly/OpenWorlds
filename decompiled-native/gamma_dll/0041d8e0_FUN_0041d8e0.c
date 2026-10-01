// 0041d8e0 FUN_0041d8e0 [Global]
// program: gamma.dll

int __cdecl
FUN_0041d8e0(int param_1,undefined4 *param_2,uint *param_3,byte *param_4,undefined4 *param_5)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 1;
  pbVar4 = (byte *)*param_2;
  iVar2 = 0;
  uVar3 = *param_3;
  if (1 < param_1) {
    do {
      if ((*pbVar4 & uVar3) != 0) {
        iVar2 = iVar2 + iVar5;
      }
      uVar3 = uVar3 * 2;
      pbVar1 = pbVar4;
      if (uVar3 == 0x100) {
        uVar3 = 1;
        pbVar1 = pbVar4 + 1;
        if (param_4 <= pbVar4 + 1) {
          *param_5 = 1;
          break;
        }
      }
      pbVar4 = pbVar1;
      iVar5 = iVar5 * 2;
    } while (iVar5 < param_1);
  }
  *param_2 = pbVar4;
  *param_3 = uVar3;
  return iVar2;
}



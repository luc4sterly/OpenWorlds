// 10007840 RwImmediateBegin [Global]
// programa: RWL21.DLL

void RwImmediateBegin(int *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined1 *puVar3;
  
                    /* 0x7840  278  RwImmediateBegin */
  rwupdateViewMatrix(*(int *)(PTR_DAT_1005b69c + 0x10));
  iVar1 = *(int *)(PTR_DAT_1005b69c + 0x10);
  *(undefined4 *)(iVar1 + 0x80) = *(undefined4 *)(iVar1 + 0x74);
  *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar1 + 0x78);
  *(undefined4 *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x88) =
       *(undefined4 *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x7c);
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (iVar1 < 0) {
      *param_1 = 0;
      param_1[2] = param_1[2] + iVar1;
    }
    iVar1 = param_1[1];
    if (iVar1 < 0) {
      param_1[1] = 0;
      param_1[3] = param_1[3] + iVar1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x100) + 0x1c);
    if (iVar1 < param_1[2] + *param_1) {
      param_1[2] = iVar1 - *param_1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x100) + 0x20);
    if (iVar1 < param_1[3] + param_1[1]) {
      param_1[3] = iVar1 - param_1[1];
    }
    if ((0 < param_1[2]) && (0 < param_1[3])) {
      (**(code **)(PTR_DAT_1005b69c + 0x40))(param_1);
      *(undefined4 *)(PTR_DAT_1005b69c + 0x348) = 1;
      goto LAB_10007930;
    }
  }
  *(undefined4 *)(PTR_DAT_1005b69c + 0x348) = 0;
LAB_10007930:
  pcVar2 = FUN_10029210;
  if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
    pcVar2 = (code *)&LAB_10027510;
  }
  puVar3 = FUN_1002a7d0(pcVar2,0x3f);
  *(undefined1 **)(PTR_DAT_1005b69c + 0x2f4) = puVar3;
  *(int *)(PTR_DAT_1005b69c + 0x340) = *(int *)(PTR_DAT_1005b69c + 0x10) + 0xbc;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2f0) = 0x3f;
  return;
}



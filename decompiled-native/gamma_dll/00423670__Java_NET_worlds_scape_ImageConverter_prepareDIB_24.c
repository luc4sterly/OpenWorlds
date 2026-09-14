// 00423670 _Java_NET_worlds_scape_ImageConverter_prepareDIB@24 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_ImageConverter_prepareDIB_24
               (int *param_1,undefined4 param_2,LONG param_3,int param_4,int param_5,
               undefined4 param_6)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  HDC hdc;
  HBITMAP pHVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 local_418;
  undefined1 auStack_414 [1020];
  void *local_18;
  undefined4 local_14;
  
                    /* 0x23670  238  _Java_NET_worlds_scape_ImageConverter_prepareDIB@24 */
  puVar9 = (undefined4 *)0x0;
  if (param_5 != 0) {
    puVar6 = (undefined1 *)(**(code **)(*param_1 + 0x2ec))(param_1,param_6,0);
    iVar10 = 0;
    if (0 < param_5) {
      puVar8 = puVar6;
      if (8 < param_5) {
        do {
          *(undefined1 *)(&local_418 + iVar10) = *puVar8;
          *(undefined1 *)((int)&local_418 + iVar10 * 4 + 1) = puVar8[1];
          *(undefined1 *)((int)&local_418 + iVar10 * 4 + 2) = puVar8[2];
          *(undefined1 *)((int)&local_418 + iVar10 * 4 + 3) = 0;
          auStack_414[iVar10 * 4] = puVar8[4];
          auStack_414[iVar10 * 4 + 1] = puVar8[5];
          auStack_414[iVar10 * 4 + 2] = puVar8[6];
          auStack_414[iVar10 * 4 + 3] = 0;
          auStack_414[iVar10 * 4 + 4] = puVar8[8];
          auStack_414[iVar10 * 4 + 5] = puVar8[9];
          auStack_414[iVar10 * 4 + 6] = puVar8[10];
          auStack_414[iVar10 * 4 + 7] = 0;
          auStack_414[iVar10 * 4 + 8] = puVar8[0xc];
          auStack_414[iVar10 * 4 + 9] = puVar8[0xd];
          auStack_414[iVar10 * 4 + 10] = puVar8[0xe];
          auStack_414[iVar10 * 4 + 0xb] = 0;
          auStack_414[iVar10 * 4 + 0xc] = puVar8[0x10];
          auStack_414[iVar10 * 4 + 0xd] = puVar8[0x11];
          auStack_414[iVar10 * 4 + 0xe] = puVar8[0x12];
          auStack_414[iVar10 * 4 + 0xf] = 0;
          auStack_414[iVar10 * 4 + 0x10] = puVar8[0x14];
          auStack_414[iVar10 * 4 + 0x11] = puVar8[0x15];
          auStack_414[iVar10 * 4 + 0x12] = puVar8[0x16];
          auStack_414[iVar10 * 4 + 0x13] = 0;
          auStack_414[iVar10 * 4 + 0x14] = puVar8[0x18];
          auStack_414[iVar10 * 4 + 0x15] = puVar8[0x19];
          auStack_414[iVar10 * 4 + 0x16] = puVar8[0x1a];
          auStack_414[iVar10 * 4 + 0x17] = 0;
          auStack_414[iVar10 * 4 + 0x18] = puVar8[0x1c];
          auStack_414[iVar10 * 4 + 0x19] = puVar8[0x1d];
          auStack_414[iVar10 * 4 + 0x1a] = puVar8[0x1e];
          auStack_414[iVar10 * 4 + 0x1b] = 0;
          iVar10 = iVar10 + 8;
          puVar8 = puVar8 + 0x20;
        } while (iVar10 < param_5 + -8);
      }
      for (; iVar10 < param_5; iVar10 = iVar10 + 1) {
        *(undefined1 *)(&local_418 + iVar10) = *puVar8;
        *(undefined1 *)((int)&local_418 + iVar10 * 4 + 1) = puVar8[1];
        puVar1 = puVar8 + 2;
        puVar8 = puVar8 + 4;
        *(undefined1 *)((int)&local_418 + iVar10 * 4 + 2) = *puVar1;
        *(undefined1 *)((int)&local_418 + iVar10 * 4 + 3) = 0;
      }
    }
    local_14 = DAT_004714ac;
    uVar2 = local_14;
    if (iVar10 < 0x100) {
      puVar9 = &local_418 + iVar10;
      local_14._1_1_ = (undefined1)((uint)DAT_004714ac >> 8);
      uVar3 = local_14._1_1_;
      local_14._2_1_ = (undefined1)((uint)DAT_004714ac >> 0x10);
      uVar4 = local_14._2_1_;
      local_14._3_1_ = (undefined1)((uint)DAT_004714ac >> 0x18);
      uVar5 = local_14._3_1_;
      local_14 = uVar2;
      do {
        iVar10 = iVar10 + 1;
        *(undefined1 *)puVar9 = (undefined1)local_14;
        *(undefined1 *)((int)puVar9 + 1) = uVar3;
        *(undefined1 *)((int)puVar9 + 2) = uVar4;
        *(undefined1 *)((int)puVar9 + 3) = uVar5;
        puVar9 = puVar9 + 1;
      } while (iVar10 < 0x100);
    }
    puVar9 = &local_418;
    (**(code **)(*param_1 + 0x30c))(param_1,param_6,puVar6,0);
  }
  hdc = CreateCompatibleDC((HDC)0x0);
  if (puVar9 == (undefined4 *)0x0) {
    iVar10 = 4;
  }
  else {
    iVar10 = 1;
  }
  pHVar7 = FUN_00422150(hdc,param_3,param_4,puVar9,&local_18,iVar10,0);
  DeleteDC(hdc);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d1a4,pHVar7);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d1a8,local_18);
  return;
}



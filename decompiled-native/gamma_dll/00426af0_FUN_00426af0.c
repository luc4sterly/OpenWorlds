// 00426af0 FUN_00426af0 [Global]
// program: gamma.dll

undefined8 __thiscall FUN_00426af0(void *this,undefined2 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined3 uVar8;
  int iVar7;
  undefined2 *puVar9;
  bool bVar10;
  
  DAT_0049d270 = param_2;
  DAT_0049d274 = param_3;
  DAT_0049d26c = param_1;
  iVar7 = *(int *)((int)this + 4);
  DAT_0049d278 = iVar7;
  if (param_3 != 0) {
    iVar2 = CONCAT31(CONCAT21((short)((uint)param_1 >> 0x10),(char)*param_1),
                     (char)((ushort)*param_1 >> 8));
    puVar9 = param_1 + 1;
    bVar5 = 8;
    iVar6 = param_3;
    do {
      while( true ) {
        uVar8 = (undefined3)((uint)iVar7 >> 8);
        uVar1 = *(undefined1 *)CONCAT31(uVar8,(char)((uint)iVar2 >> 8));
        iVar7 = CONCAT31(uVar8,uVar1);
        *param_2 = uVar1;
        param_2 = param_2 + 1;
        bVar3 = *(byte *)(iVar7 + 0x100);
        bVar10 = bVar5 < bVar3;
        bVar5 = bVar5 - bVar3;
        if (bVar10) break;
        iVar2 = iVar2 << (bVar3 & 0x1f);
        iVar6 = iVar6 + -1;
        if (iVar6 == 0) goto LAB_00426b87;
      }
      bVar3 = bVar3 + bVar5;
      uVar1 = *(undefined1 *)puVar9;
      puVar9 = (undefined2 *)((int)puVar9 + 1);
      bVar4 = -bVar5;
      bVar5 = bVar5 + 8;
      iVar2 = CONCAT31((int3)((uint)(iVar2 << (bVar3 & 0x1f)) >> 8),uVar1) << (bVar4 & 0x1f);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
LAB_00426b87:
    param_1 = (undefined2 *)((int)puVar9 + (-1 - (uint)((char)(bVar5 >> 4 | bVar5 << 4) < '\0')));
  }
  DAT_0049d268 = param_1;
  return CONCAT44(param_3,(int)param_1 - (int)DAT_0049d26c);
}



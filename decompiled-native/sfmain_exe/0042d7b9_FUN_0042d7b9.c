// 0042d7b9 FUN_0042d7b9 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042d7b9(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if ((DAT_0043ea64 != 0) && (DAT_0043e838 != -2)) {
    lVar5 = FUN_0042d85a(param_1,param_2);
    uVar1 = 0;
    if ((int)lVar5 == 0) goto LAB_0042d840;
    puVar2 = VirtualAlloc((LPVOID)0x0,in_EAX,0x1000,0x40);
    uVar1 = 0;
    if (puVar2 == (uint *)0x0) goto LAB_0042d840;
    uVar3 = in_EAX - 4;
    if ((uVar3 <= in_EAX) && (0x37 < uVar3)) {
      *puVar2 = uVar3;
      uVar6 = FUN_0042d745(extraout_ECX,puVar2);
      iVar4 = (int)((ulonglong)uVar6 >> 0x20);
      *(uint *)uVar6 = *(uint *)uVar6 | 1;
      *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
      FUN_0042b9b8();
      uVar1 = 1;
      goto LAB_0042d840;
    }
  }
  uVar1 = 0;
LAB_0042d840:
  return CONCAT44(param_2,uVar1);
}



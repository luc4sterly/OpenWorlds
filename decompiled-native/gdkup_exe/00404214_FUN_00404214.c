// 00404214 FUN_00404214 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00404214(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 in_EAX;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_00405bad(param_1,in_EAX);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  piVar2 = (int *)uVar4;
  if ((((piVar2 != (int *)0x0) && (*piVar2 == 0)) && (*(int *)(iVar3 + 4) != *(int *)(iVar3 + 9)))
     && ((uVar1 = *(ushort *)piVar2[1], uVar1 < 2 || ((4 < uVar1 && ((uVar1 < 6 || (0xb < uVar1)))))
         ))) {
    FUN_00405c57();
  }
  return CONCAT44(param_2,piVar2);
}



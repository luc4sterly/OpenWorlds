// 00406bcd FUN_00406bcd [Global]
// programa: gdkup.exe

/* WARNING: Unable to track spacebase fully for stack */

undefined8 __fastcall FUN_00406bcd(undefined4 param_1,int param_2)

{
  int iVar1;
  PVOID in_EAX;
  int *unaff_FS_OFFSET;
  
  if (*(PVOID *)((int)in_EAX + 0x2c) != (PVOID)*unaff_FS_OFFSET) {
    RtlUnwind(*(PVOID *)((int)in_EAX + 0x2c),(PVOID)0x406bed,(PEXCEPTION_RECORD)0x0,in_EAX);
  }
  (*(code *)PTR_FUN_00408f40)();
  iVar1 = *(int *)((int)in_EAX + 0x1c);
  *(undefined4 *)(iVar1 + -4) = *(undefined4 *)((int)in_EAX + 0x18);
  if (param_2 == 0) {
    param_2 = 1;
  }
  *(int *)(iVar1 + -8) = param_2;
  verr();
  verr();
  verr();
  return CONCAT44(*(undefined4 *)((int)in_EAX + 8),*(undefined4 *)(iVar1 + -8));
}



// 1000995f FUN_1000995f [Global]
// program: RWDLDD21.DLL

/* WARNING: Removing unreachable block (ram,0x100099d6) */
/* WARNING: Removing unreachable block (ram,0x100099c8) */
/* WARNING: Removing unreachable block (ram,0x100099fb) */
/* WARNING: Removing unreachable block (ram,0x10009a0b) */
/* WARNING: Removing unreachable block (ram,0x10009a0d) */
/* WARNING: Removing unreachable block (ram,0x10009a1d) */
/* WARNING: Removing unreachable block (ram,0x10009a1f) */
/* WARNING: Removing unreachable block (ram,0x10009a58) */
/* WARNING: Removing unreachable block (ram,0x10009a5c) */
/* WARNING: Removing unreachable block (ram,0x10009a6a) */
/* WARNING: Removing unreachable block (ram,0x10009ab8) */
/* WARNING: Removing unreachable block (ram,0x10009a76) */
/* WARNING: Removing unreachable block (ram,0x10009ae8) */
/* WARNING: Removing unreachable block (ram,0x10009a45) */
/* WARNING: Removing unreachable block (ram,0x10009a4d) */

undefined4 FUN_1000995f(void)

{
  int iVar1;
  undefined4 *unaff_EDI;
  char in_SF;
  char in_OF;
  int unaff_retaddr;
  
  if ((in_OF != in_SF) && (iVar1 = DirectDrawCreate(), iVar1 == 0)) {
    iVar1 = (**(code **)*unaff_EDI)(unaff_EDI,&DAT_10034110,&stack0xfffffff8);
    if (iVar1 == 0) {
      (**(code **)(iRam00000000 + 0x10))(0,&LAB_10009920,&stack0xfffffff0);
    }
    if (&stack0x00000000 != (undefined1 *)0x0) {
      (**(code **)(unaff_retaddr + 8))(&stack0x00000000);
    }
  }
  return 1;
}



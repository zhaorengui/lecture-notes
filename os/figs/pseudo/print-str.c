copy_from_user(buffer, p, count);        /* p is the kernel bufer */
for (i = 0; i < count; i++) {            /* loop on every character */
  while(*printer_status_reg != READY);   /* loop until ready */
  *printer_data_register = p[i];         /* output one character */
}
return_to_user();

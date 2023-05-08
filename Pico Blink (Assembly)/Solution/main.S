.section .boot2
.globl _entry

_entry:
    // Set the stack pointer
    ldr r0, =0x20042000
    mov sp, r0

    // Initialize GPIO 25
    mov r0, #25
    mov r1, #5
    ldr r2, =0x40020000
    str r1, [r2, r0, lsl #2]

blink_loop:
    // Toggle GPIO 25
    ldr r1, [r2, r0, lsl #2]
    eor r1, r1, #0x20
    str r1, [r2, r0, lsl #2]

    // Delay loop
    mov r3, #0x3FFFF
delay_loop:
    sub r3, r3, #1
    cmp r3, #0
    bne delay_loop

    // Repeat
    b blink_loop

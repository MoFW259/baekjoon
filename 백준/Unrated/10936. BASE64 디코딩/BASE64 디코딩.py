import base64

s = input().strip()

s_bytes = s.encode('utf-8')

decoded = base64.b64decode(s_bytes)

print(decoded.decode('utf-8'))

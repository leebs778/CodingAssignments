import re

scrilla = ['abc123', 'gitmoney', '#abc123', '123456789', '1234556678910']
founditems = re.search(r'\d{6}', scrilla)
if founditems:
	print founditems

curl https://api.openai.com/v1/completions \
  -H 'Content-Type: application/json' \
  -H "Authorization: Bearer $OPENAI_API_KEY" \
  -d '{
  "model": "code-davinci-002",
  "prompt": "Write a linked list implementation in c",
  "max_tokens": 4000,
  "temperature": 1.0
}' \
--insecure

The problem:
- For N banks and M services, we will build N*M software programs. This is Many to Many relationships.
- With every new service, the banks need to wait a lot till the service provide solutions for the banks
- With every new bank, it has to search the market for which services are available. Bank has to implement software per service to communicate
- There will be a lot of time to discuss agreements on commission per transaction
- Code wise, most of the codes will be implemented with several different teams, and there will be a lot of code duplications 


The business opportunity:
- Introduce a company that acts as middle players between banks and services
- Each bank builds one software ONLY to contact the middle
    - It asks to get the bills of a specific service to view them to the user
    - If a customer asked to pay a bill, the bank verifies the balance, and send to the middle to mark the bill as paid
- Each service builds one software ONLY to contact the middle
    - It provides the bills to the middle and marks them paid if they are paid
- Middle build N software for banks and M for services
    - This means we now build 2N + 2M software projects not N*M
    - N+M by the middle. As one company, a lot of code can be shared not duplicate
- If there is a new bank, it only needs to build one software from its side to get access directly for M services
- This means the system scales very well
- This is the core idea of Fawry company in Egypt, and similar ones abroad
    - Fawry is a middle layer that takes commissions on transactions that happen through it
    
    
Like any business
- You don't only depend on your elegant solution if it is elegant even :D
- Also a lot of effort to validate your business model, and market it
- Read links in the homework slides


Technical question:
- How the middle can avoid duplication in code when say dealing with banks?
